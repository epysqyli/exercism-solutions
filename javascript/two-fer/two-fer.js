// export const twoFer = (name) => {
//   if (name == undefined) {
//     return 'One for you, one for me.'
//   }
//   else {
//     return `One for ${name}, one for me.`
//   }
// };

// export const twoFer = (name) => {
//   return name == undefined ? 'One for you, one for me.' : `One for ${name}, one for me.`
// };

export const twoFer = (name = 'you') => {
  return `One for ${name}, one for me.`
};
