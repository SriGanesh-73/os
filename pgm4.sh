triangle_area(){
	echo "Triangle Area:"
	read -p "Enter the base of the triangle:" base
	read -p "Enter the height of the triangle:" height
	area=$(echo "0.5 * $base * $height" | bc)
      	echo "Area of the triangle is : $area"
}
rectangle_area(){
	echo "Rectangle Area:"
	read -p "Enter length:" length
	read -p "Enter width:" width
	area=$((length * width))
	echo "The area of the rectangle is :$area"
}
square_area(){
	echo "Square Area:"
	read -p "Enter the side of the square:" side
	area=$((side * side))
	echo "The area of the square is:$area"
}
triangle_area
rectangle_area
square_area
