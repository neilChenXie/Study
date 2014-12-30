var new_b = new Buffer(process.argv);

console.log(new_b.slice(2).toString('hex'));
