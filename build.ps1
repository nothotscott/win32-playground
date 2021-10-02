param (
	[switch]$clean = $false,
	[switch]$build = $true,
	[switch]$run = $false
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