echo "Enter the Number";
read N;
x=0;
y=1;

echo "Fibonacci Series is : ";

for (( i = 1; i <= N; i++))
do
	echo " $x";
	temp=$(( $x + $y));
	x=$y;
	y=$temp;
done;
