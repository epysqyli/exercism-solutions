class Lasagna
{
    int cookingTime = 40;
    int minPerLayer = 2;

    public int ExpectedMinutesInOven() {
        return cookingTime;
    }

    public int RemainingMinutesInOven(int goneMinutes) {
        return (cookingTime - goneMinutes);
    }

    public int PreparationTimeInMinutes(int layers) {
        return (minPerLayer * layers);
    }

    public int ElapsedTimeInMinutes(int layers, int goneMinutes) {
        return (goneMinutes + PreparationTimeInMinutes(layers));
    }
}
