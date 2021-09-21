class HighScores
  def initialize(scores)
    @scores = scores
  end

  attr_reader :scores

  def latest
    @scores.last
  end

  def personal_best
    @scores.max
  end

  def personal_top_three
    @scores.sort.reverse[0, 3]
  end

  def latest_is_personal_best?
    latest = @scores.last
    rest = @scores[0, @scores.length - 1]
    rest.all? { |score| score < latest }
  end
end