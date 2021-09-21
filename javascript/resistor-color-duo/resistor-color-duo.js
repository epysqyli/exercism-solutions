import "core-js";

export const decodedValue = ([color1, color2]) => {
  let colorCodes = [
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white",
  ];

  return colorCodes.indexOf(color1) * 10 + colorCodes.indexOf(color2);
};
