echo "Enter two Numbers";
read a; read b;

echo "1.Addition"
echo "2.Substration"
echo "3.Multiplication"
echo "4.Division"

echo "Choose an Option";
read op;

case $op in
1)
	result=$(( $a + $b ))
	echo "Sum: $result";;
2)
	result=$(( $a - $b ))
	echo "Difference: $result";;
3)
	result=$(( $a * $b ))
	echo "Product: $result";;
4)
	result=$(( $a / $b ))
	echo "Quotient: $result";;
*)
	echo "Wrong Choice";;
esac
