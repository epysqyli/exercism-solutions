class Triangle
  def initialize(sides_length)
    @a = sides_length[0]
    @b = sides_length[1]
    @c = sides_length[2]
    @max = sides_length.sort.reverse[0]
    @rest_sum = sides_length.sort.reverse[1] + sides_length.sort.reverse[2]
  end

  def violates_inequality?
    @max > @rest_sum
  end

  def equilateral?
    return false if @a.zero?

    @a == @b && @a == @c ? true : false
  end

  def isosceles?
    return false if violates_inequality?

    true if @a == @b || @a == @c || @b == @c
  end

  def scalene?
    return false if violates_inequality?

    true if @a != @b && @a != @c && @b != @c
  end
end
