if (-Not (Test-Path "./vcpkg")) {
    git clone https://github.com/microsoft/vcpkg.git
}

cd vcpkg
.\bootstrap-vcpkg.bat
cd ..
.\vcpkg\vcpkg.exe install

New-Item -ItemType Directory -Path "third-party" -ErrorAction SilentlyContinue
cd third-party

if (-Not (Test-Path "./chess-library")) {
    git clone https://github.com/Disservin/chess-library.git
}

cd ..