clear
g++ app.cpp -DEVAL -std=gnu++17 -O2 -pipe -static -s -o out
echo ----- ----- -----
echo   Build  Output
echo ----- ----- -----
./out
