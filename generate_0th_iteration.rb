# Generate 0.xml

# Generate Header
puts "<states>"
puts "<itno>0</itno>"
puts "<agents>"
NumBuyers = 100
NumFirms = 10
# Generate Buyers
for i in 1..NumBuyers do 
	puts "<xagent>"
	puts "<name>buyer</name>"
	puts "<my_id>#{i}</my_id>"
	firm = 100 + 1 + rand(NumFirms)
	puts "<firm_id>#{firm}</firm_id>"
	puts "<my_qual>1</my_qual>"
	puts "</xagent>"
end
#Generate Firms
for i in 1..NumFirms do 
	puts "<xagent>"
	puts "<name>firm</name>"
	puts "<buyer_ids>{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}</buyer_ids>"
	puts "<my_id>#{100 + i}</my_id>"
	quality = rand()
	puts "<quality>#{quality}</quality>"
	buyer = 1 + rand(NumBuyers)
	puts "<stored_id>#{buyer}</stored_id>"
	puts "</xagent>"

end
puts "</agents>"
puts "</states>"