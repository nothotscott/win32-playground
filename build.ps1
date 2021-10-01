param (
	[switch]$build = $true,	# -build:$false for nobuild
	[switch]$run = $false
)

$OUTPUT = "build"

if (!(test-path $OUTPUT)) {
	md $OUTPUT
}
cd $OUTPUT

if($build) {
	cmake -G Ninja --build ../
	ninja all
}
if($run) {
	Start-Process Win32HelloWorld
}

cd ../