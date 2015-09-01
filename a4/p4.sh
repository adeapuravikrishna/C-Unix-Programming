#! /bin/dash
debug=""
for x		# x loops through args $1, $2, ...
do
  # echo "x = $x"
  case "$x" in
    s) echo "`p1 s`";;
    p) echo "`p1 p`";;
    2) echo "`p1 | p2`";;
    3) echo "` p1 | p2 | p3 `";;
    d) echo "` p1 | p2 | dft 2 | p3 `";;
    D) debug="1"
  esac
done
