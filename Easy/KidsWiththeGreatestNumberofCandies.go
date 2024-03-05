func kidsWithCandies(candies []int, extraCandies int) []bool {
	var outArr []bool
	var max int
	for i := 0; i < len(candies); i++ {
		if max < candies[i] {
			max = candies[i]
		}

	}
	var totalcandies int
	for i := 0; i < len(candies); i++ {
		totalcandies = candies[i] + extraCandies
		if totalcandies >= max {
			outArr = append(outArr, true)
		} else {
			outArr = append(outArr, false)
		}
	}
	return outArr
}