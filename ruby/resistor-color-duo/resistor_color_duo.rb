class ResistorColorDuo
  @@mapping = { black: 0, brown: 1,
                red: 2, orange: 3,
                yellow: 4,
                green: 5,
                blue: 6,
                violet: 7,
                grey: 8,
                white: 9 }

  def self.value(bands)
    a = @@mapping[bands[0].to_sym]
    b = @@mapping[bands[1].to_sym]
    (a.to_s + b.to_s).to_i
  end
end
