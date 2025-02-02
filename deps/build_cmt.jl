# build cmt locally

using Pkg
Pkg.activate(@__DIR__)
Pkg.instantiate()

if haskey(ENV, "BUILDKITE")
    run(`buildkite-agent annotate 'Using a locally-built cmt library; A bump of cmt_jll will be required before releasing Metal.jl.' --style 'warning' --context 'ctx-deps'`)
end

using Scratch, CMake_jll, Ninja_jll, Libdl, Preferences

Metal = Base.UUID("dde4c033-4e86-420c-a63e-0dd931031962")

# get a scratch directory
scratch_dir = get_scratch!(Metal, "cmt")
isdir(scratch_dir) && rm(scratch_dir; recursive=true)
source_dir = joinpath(@__DIR__, "cmt")

# get build directory
build_dir = if isempty(ARGS)
    mktempdir()
else
    ARGS[1]
end
mkpath(build_dir)

# build and install
cmake() do cmake_path
ninja() do ninja_path
    run(```$cmake_path -GNinja
                       -DCMAKE_BUILD_TYPE=Debug
                       -DCMAKE_INSTALL_PREFIX=$(scratch_dir)
                       -DCMAKE_COLOR_DIAGNOSTICS=$(get(stdout, :color, false) ? "On" : "Off")
                       -B$(build_dir) -S$(source_dir)```)
    run(`$cmake --build $(build_dir) --parallel $(Sys.CPU_THREADS)`)
    run(`$ninja_path -C $(build_dir) install`)
end
end

# Discover built libraries
built_libs = filter(readdir(joinpath(scratch_dir, "lib"))) do file
    endswith(file, ".$(Libdl.dlext)")
end
lib_path = joinpath(scratch_dir, "lib", only(built_libs))
isfile(lib_path) || error("Could not find library $lib_path in build directory")

# Tell cmt_jll to load our library instead of the default artifact one
set_preferences!(
    joinpath(dirname(@__DIR__), "LocalPreferences.toml"),
    "cmt_jll",
    "libcmt_path" => lib_path;
    force=true,
)

# Copy the preferences to `test/` as well to work around Pkg.jl#2500
cp(joinpath(dirname(@__DIR__), "LocalPreferences.toml"),
   joinpath(dirname(@__DIR__), "test", "LocalPreferences.toml"); force=true)
