# Barcode-verification
One of the features of using barcodes in the fight against counterfeit products (fake products sold under the name of a manufacturer) is the use of special protocols. The fight against counterfeiting is based on hidden and open manufacturer markings. Typically, such markings consist of two or more parts. The open part may contain a barcode (such as EAN-13), which, for example, in European practice, shows the country of origin of the product by the first three digits, the next four digits represent the product code, and the following four digits represent the company code, and the last digit is a control digit. Additionally, this information can be presented in alphanumeric form in different languages, along with trademarks and the company's email address.

All of this information is sufficient to contact the manufacturer. Encoding the hidden part is individual for each product and consists of a set of randomly generated program digits and machine-readable symbols. The hidden part cannot be read without violating the integrity of the product or packaging or without removing the erasable layer of paint (similar to the protection of sports lottery tickets).

The manufacturer creates a unique electronic database with non-repeating identifiers identical to the hidden marking on the product. When a customer makes the first request to the enterprise to confirm the authenticity of the product code, this code is deleted to another database, i.e., second and subsequent authorizations are impossible. If the first presentation of a unique code does not match or if it is presented again, you can start fighting counterfeiters.

This same system also eliminates the sale of unaccounted for products produced at the enterprise. In addition, it eliminates gross EAN-13 barcode counterfeits if they do not correspond to the code assigned by the enterprise. There is a simple algorithm for checking the EAN-13 code.

Code verification algorithm:

1. Add up the digits in even positions Sr.
2. Multiply Sr*3=S1
3. Add up the digits in odd positions Sн (excluding the control digit)
4. Obtain S=S1+Sн
5. Leave only the number in the least significant digit of S (t)
6. Find the difference P=10-t

For a correct code, P should match the control digit.

Example: 8590721001209
1. Sr=5+0+2+0+1+0=8
2. S1=8*3=24
3. Sн=8+9+7+1+0+2=27
4. S=24+27=51
5. t=1
6. P=10-1=9 (matches the control digit)

Let's change any digit in the code, for example, 7 to 5.
Then:
3. Sн=8+9+5+1+0+2=25
4. S=24+25=79
5. t=9
6. P=10-9=1, i.e., the control digit indicates the sensitivity of the code (it does not match).
