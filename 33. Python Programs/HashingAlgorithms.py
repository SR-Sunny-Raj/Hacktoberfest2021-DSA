import hashlib

md5_result = hashlib.md5(b"Test password").hexdigest()
sha256_result = hashlib.sha256(b"Test password").hexdigest()
sha384_result = hashlib.sha384(b"Test password").hexdigest()
sha224_result = hashlib.sha224(b"Test password").hexdigest()
sha512_result = hashlib.sha512(b"Test password").hexdigest()
sha1_result = hashlib.sha1(b"Test password").hexdigest()

print(f"md5    - {md5_result}")
print(f"sha256 - {sha256_result}")
print(f"sha384 - {sha384_result}")
print(f"sha224 - {sha224_result}")
print(f"sha512 - {sha512_result}")
print(f"sha1   - {sha1_result}")

'''
Input: Test password
Output:
md5    - 'ffe24c9204d65518429aa701f3a6bdc5'
sha256 - 'db1bc48640c099bdc6d02c23a9d278edc7024b9eb15fad8925ec7a19f6350a39'
sha384 - 'f95c877c6c5b4b949ce2787c91b7e30783971438e9912f3a0d38452cd80a7be3865efe794c8ba002af089d57b13c836c'
sha224 - 'a903507dd0a68bb1e2a34dab4416e1f4c0022ac1d84e32b23c96d158'
sha512 - 'f9cfe230de89e0ec1cb714ef355771ae84fe22040258f97e3910ee889ac74412f97a9848e846cab9c5b0077e76422e4c47e3ed6615073bca0ccdac2fee226cec'
sha1   - '5bcaa7fe92fe36be87fbc274874dbe7a60926669'
'''