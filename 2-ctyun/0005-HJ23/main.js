const rl = require('readline').createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

function removeWords(s) {
  // map记录字符次数
  let tmap = {};
  for (let i = 0; i < s.length; ++i) {
    const ch = s[i];
    if (tmap.hasOwnProperty(ch)) {
      tmap[ch] = tmap[ch] + 1;
    } else {
      tmap[ch] = 1;
    }
  }

  // 找出最小字数字符
  let flag = 0;
  let tmp = [];
  for (let key in tmap) {
    const val = tmap[key];
    if (flag === 0) {
      flag = val;
      tmp.push(key);
      continue;
    }
    if (flag > val) {
      tmp = [];
      tmp.push(key);
      flag = val;
    } else if (flag === val) {
      tmp.push(key);
    }
  }
  tmap = null;

  // 删除字符
  let ret = s;
  tmp.forEach((ch) => {
    const reg = new RegExp(ch, 'g');
    ret = ret.replace(reg, '');
  });
  tmp = null;
  return ret;
}

void (async function () {
  // Write your code here
  while ((line = await readline())) {
    console.log(removeWords(line));
  }
})();
