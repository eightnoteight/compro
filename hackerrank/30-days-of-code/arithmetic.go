package main

import (
	"fmt"
	"math"
)

func simpleround(x float64) float64 {
	if x < 0 {
		return math.Ceil(x - 0.5)
	}
	return math.Floor(x + 0.5)
}

func main() {
	var m float64
	var t, x int
	fmt.Scanf("%f\n%d\n%d", &m, &t, &x)
	fmt.Printf(
		"The final price of the meal is $%d.\n",
		int(simpleround(m*(1+(float64(t+x)/100.0)))))
}
