#Calculate Compound Interest
def calc_si(principal, term, interest_rate):
    amount = principal * ((1 + interest_rate / 100) ** term)
    comp_int = amount - principal
    return "Compound interest is {:.2f} and total amount is {:.2f}".format(comp_int, amount)