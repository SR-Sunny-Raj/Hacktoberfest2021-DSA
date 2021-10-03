<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>JavaScript form validation - checking email</title>
<link rel='stylesheet' href='form-style.css' type='text/css' />      
</head>
<body onload='document.form1.text1.focus()'>
<div class="mail">
<h2>Input an email and Submit</h2>
<form name="form1" action="#"> 
<ul>
<li><input type='text' name='text1'/></li>
<li>&nbsp;</li>
<li class="submit"><input type="submit" name="submit" value="Submit" onclick="ValidateEmail(document.form1.text1)"/></li>
<li>&nbsp;</li>
</ul>
</form>
</div>
<script>
function ValidateEmail(inputText)
{
var mailformat = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
if(inputText.value.match(mailformat))
{
alert("Valid email address!");
document.form1.text1.focus();
return true;
}
else
{
alert("You have entered an invalid email address!");
document.form1.text1.focus();
return false;
}
}

</script>
</body>
</html>
