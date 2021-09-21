class SpaceAge
  def initialize(age)
    @age = age
    @earth_year = 31_557_600.0
  end

  def on_earth
    @age /= @earth_year
    @age.round(2)
  end

  def on_mercury
    orbital_period = 0.2408467
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_venus
    orbital_period = 0.61519726
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_mars
    orbital_period = 1.8808158
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_jupiter
    orbital_period = 11.862615
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_saturn
    orbital_period = 29.447498
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_uranus
    orbital_period = 84.016846
    @age /= @earth_year * orbital_period
    @age.round(2)
  end

  def on_neptune
    orbital_period = 164.79132
    @age /= @earth_year * orbital_period
    @age.round(2)
  end
end
