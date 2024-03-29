param([string]$Name, [string[]]$Files)

$DIR = "atividades/$Name"

function Get-Snippet {
  param([scriptblock]$Format, [string] $Separator)

  $Files `
    | ForEach-Object $format `
    | Join-String -Separator $Separator
}

function New-File {
  param([string]$Name, [string]$Content)

  $filename = "$DIR/$Name"
  New-Item -Name $filename
  Add-Content -Path $filename -Value $Content
}

mkdir $DIR

foreach($file in $Files)
{
  New-Item -ItemType HardLink -Name "$DIR/$file.c" -Value "src/$file.c"
  New-Item -ItemType HardLink -Name "$DIR/$file.h" -Value "src/$file.h"
}

$include = Get-Snippet -Format { "#include `"$_.h`"" } -Separator "`n"
$initializer = Get-Snippet -Format { "$_* $($_.ToLower()) = $($_.ToLower())Alloc();" } -Separator "`n`t"

New-File -Name main.c -Content "$include

int main(void) {
  $initializer

  // TODO

  return 0;
}"

New-File -Name Makefile -Content "CC=gcc

build:
	`$(CC) *.c -o app.exe"
