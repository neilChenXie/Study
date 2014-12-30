u32a = new Uint32Array(1);
u32a[0] = process.argv[2];
//console.log(process.argv[2]);
//console.log(u32a[0]);
//console.log(u32a.buffer);
ui16 = new Uint16Array(u32a.buffer);
//console.log(ui16.buffer);
//console.log(ui16[0]);
console.log(JSON.stringify(ui16));
