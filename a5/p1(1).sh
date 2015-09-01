read data
echo '<html><head><title>a5/p1.sh</title></head>
<body bgcolor=white text=black>
<form method=POST action="/prog/osp?a5+p1.sh">
Data: <input type=submit name=data value="sine">
<input type=submit name=data value="sum">
<input type=submit name=data value="product"><br>
View: <input type=submit name=data value="data">
<input type=submit name=data value="avg">
<input type=submit name=data value="peaks">
<input type=submit name=data value="avg|peaks">
<input type=submit name=data value="dft">
<input type=submit name=data value="dft|peaks">'
#echo "<br>data = \"$data\""
case "$data" in
    sine)../a4/p1>p1.out ;;
     sum)../a4/p1 s>p1.out;;
 product)../a4/p1 p>p1.out;;
esac
if [ "$data"=true ]
then
case "$data" in
    data)plot < p1.out > plot.gif;;
     avg)../a4/p2 < p1.out | plot > plot.gif;;
   peaks)../a4/p3<p1.out | plot > plot.gif;;
"avg|peaks")../a4/p2 < p1.out | ../a4/p3 | plot > plot.gif;;
dft)dft 2 < p1.out | plot > plot.gif;;
"dft|peaks")dft 2 < p1.out | ../a4/p3 | plot > plot.gif;;
esac
fi
echo "<p><img src=\"/prog/osp?view+a5+plot.gif\">"
echo '</form></body></html>'
