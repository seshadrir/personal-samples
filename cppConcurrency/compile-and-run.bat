set filename=%1
echo %filename%

setlocal
set filename=%1
echo filename
set PATH=C:\Qt\Qt5.4.0\Tools\mingw491_32\bin;%PATH%
g++ -c -pipe -std=c++11 -g -frtti -Wall -Wextra -fexceptions -mthreads -DUNICODE -I'.' -o %filename%.o %filename%
g++ -Wl,-subsystem,console -mthreads -o %filename%.exe %filename%.o  
del %filename%.o  
%filename%.exe
 
