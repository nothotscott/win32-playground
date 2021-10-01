param (
	[switch]$clean = $false,	# -clean:$true for clean
	[switch]$build = $true,		# -build:$false for no-build
	[switch]$run = $false		# -clean:$true for run
)

$OUTPUT = "build"

if (!(test-path $OUTPUT)) {
	md $OUTPUT
}
cd $OUTPUT

if($clean) {
	Get-ChildItem -Path . -Include * | remove-Item -recurse 
}
if($build) {
	cmake -G Ninja --build ../
	ninja all
}
if($run) {
	Start-Process Win32HelloWorld
}

cd ../