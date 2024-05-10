::compilamos el motor
call updateSubmodule.bat
cd VeryReal\VeryRealSolucion\dependencies\cMake
call All.bat
cd ..\..\
msbuild "OvejaVeganaSolucion.sln" /p:configuration=Debug /p:Platform=x64 /p:PlatformToolset=v143
msbuild "OvejaVeganaSolucion.sln" /p:configuration=Release /p:Platform=x64 /p:PlatformToolset=v143
cd VeryReal\VeryRealSolucion
::copiamos la carpeta entera de bin a bin de juego
xcopy bin .\..\..\bin\ /s /e


cd ..\..\bin

ren  VeryRealProyecto_Release*.exe ______OvejaVegana_______*.exe
start .
