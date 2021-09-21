class Year
  def self.leap?(year)
    res = true if (year % 4).zero?
    res = false if (year % 100).zero?
    res = true if (year % 100).zero? && (year % 400).zero?
    res
  end
end
