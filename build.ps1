param (
	[switch]$build = $true,
	[switch]$run = $false
)

$OUTPUT = "build"

if (!(test-path $OUTPUT)) {
	md $OUTPUT
}
cd $OUTPUT

if($build) {
	cmake -G Ninja ../
	ninja all
}
if($run) {
	Start-Process Win32HelloWorld
}

cd ../