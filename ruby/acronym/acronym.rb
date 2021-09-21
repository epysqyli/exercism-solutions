class Acronym
  def self.abbreviate(string)
    words = string.split().map! { |word| word.split('-') }.flatten!
    res = String.new
    words.each do |word|
      if (word[0].ord > 64 && word[0].ord < 91) || (word[0].ord > 96 && word[0].ord < 123)
        res << word[0]
      end
    end
    res.upcase
  end
end
