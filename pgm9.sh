arithmetic_operations() {
    a=$1
    b=$2
    echo "Sum: $((a + b))"
    echo "Difference: $((a - b))"
    echo "Product: $((a * b))"
    echo "Division: $((a / b))"
}
read -p "Enter num1:" num1
read -p "Enter num2:" num2
arithmetic_operations $num1 $num2
