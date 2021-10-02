<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
title>JavaScript form validation - Password Checking - 1</title>
<link rel='stylesheet' href='form-style.css' type='text/css' />
</head>
<body onload='document.form1.text1.focus()'>
<div class="mail">
<h2>Input Password and Submit [7 to 15 characters which contain only characters, numeric digits, underscore and first character must be a letter]</h2
<form name="form1" action="#">
<ul>
<li><input type='text' name='text1'/></li>
<li class="rq">*Enter numbers only.</li>
<li>&nbsp;</li>
<li class="submit"><input type="submit" name="submit" value="Submit" onclick="CheckPassword(document.form1.text1)"/></li>
<li>&nbsp;</li>
</ul>
</form>
</div>
<script>
function CheckPassword(inputtxt) 
{ 
var passw=  /^[A-Za-z]\w{7,14}$/;
if(inputtxt.value.match(passw)) 
{ 
alert('Correct, try another...')
return true;
}
else
{ 
alert('Wrong...!')
return false;
}
}

</script>
</body>
</html>

