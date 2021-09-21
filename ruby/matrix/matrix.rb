# Class to extrapolate input matrix from string and access rows and columns
class Matrix
  attr_reader :rows, :columns

  def initialize(matrix)
    @rows = matrix.each_line.map { |row| row.split.map!(&:to_i) }
    @columns = @rows.transpose
  end
end
