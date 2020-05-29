# download
if [ -e test/ ]; then 
    rm -rf test/
fi
url=$1
oj download $url

# test
filename=$1
g++ -Wall -std=c++17 $filename
oj t 
rm -f a.out
