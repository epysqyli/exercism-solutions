class Complement
  def self.of_dna(dna)
    dna.gsub(/[CGTA]/, 'C' => 'G', 'G' => 'C', 'T' => 'A', 'A' => 'U')
  end
end
