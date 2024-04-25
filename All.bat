cd VeryReal\VeryRealSolucion\dependencies\cMake
call All.bat
cd ..
cd ..\bin
mkdir .\Assets

cd ..\..
cd ..\bin\ 

xcopy Assets .\..\VeryReal\VeryRealSolucion\bin\Assets /E /Y

cd ..\
msbuild "OvejaVeganaSolucion.sln" /p:configuration=Debug /p:Platform=x64 /p:PlatformToolset=v143
msbuild "OvejaVeganaSolucion.sln" /p:configuration=Release /p:Platform=x64 /p:PlatformToolset=v143