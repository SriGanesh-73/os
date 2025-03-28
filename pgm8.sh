gcd() {
    a=$1
    b=$2
    while [ $b -ne 0 ]; do
        temp=$b
        b=$((a % b))
        a=$temp
    done
    echo "GCD is $a"
}
read -p "Enter number1:" a
read -p "Enter number2:" b
gcd $a $b
