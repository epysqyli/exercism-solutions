export const squareRoot = (n) => {
  let root = n;
  const precision = 10 ** (-10);

  while (Math.abs(n - root ** 2) > precision) {
    root = (root + n/root)/2;
  }

  return Math.floor(root);
};
