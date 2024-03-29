param([string]$Name)

Compress-Archive `
  -Path "atividades/$Name" `
  -DestinationPath "$([Environment]::GetFolderPath("Desktop"))/Gabriel Augusto Lima Silva - Atividade $Name.zip"
