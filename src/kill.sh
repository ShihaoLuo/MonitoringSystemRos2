#！ /bin/bash

for id in $(pgrep drone) $(pgrep gui) $(pgrep estimater)
do
    kill -9 $id
    echo "killed "$id
done
