read -p "Enter the first number:" num1
read -p "Enter the second number:" num2
sum=$((num1 + num2))
diff=$((num1 - num2))
prod=$((num1 * num2))
if [ $num3 -eq 0 ]; 
then 
	quot="undefined"
else
	quot=$((num1 / num2))
fi
rem=$((num1 % num2))
echo "Sum:$sum"
echo "Difference:$diff"
echo "Product:$prod"
echo "Quotient:$quot"
echo "Remainder:$rem"

