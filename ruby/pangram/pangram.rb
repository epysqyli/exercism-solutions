class Pangram
  def self.pangram?(sentence)
    array = []
    sentence.split('').each do |char|
      char.downcase!
      array.push(char) if !!char.match(/[a-z]/) && !array.include?(char)
    end
    true if array.length == 26
  end
end
