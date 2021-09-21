export const gigasecond = (time) => {
  return new Date(time.getTime() + 10 ** 12);
};
