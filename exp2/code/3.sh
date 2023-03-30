echo "Enter two Numbers"
read a; read b;

if (( $a > $b ))
then
	echo "Largest is $a";
else
	echo "Largest is $b";
fi
