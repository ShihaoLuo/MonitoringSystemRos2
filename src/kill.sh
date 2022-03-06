#！ /bin/bash

for id in $(pgrep drone) $(pgrep gui) $(pgrep detecter) $(pgrep positioning)
do
    kill -9 $id
    echo "killed "$id
done
