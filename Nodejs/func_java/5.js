function checkUserValid(user)
{
	//console.log(user);
	return function(test_user) {
		return test_user.every(function(test_user){
			return user.some(function(user){
				return user.id === test_user.id;
			});
		});
	};
}

module.exports = checkUserValid;
