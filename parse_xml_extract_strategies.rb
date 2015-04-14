#!/bin/ruby

require 'Nokogiri'


directory = ARGV.first


puts("iteration,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10")



for i in 0..10000 do
	if (i.modulo(10) == 0)
		@doc = Nokogiri::XML(File.open(directory + i.to_s + ".xml"))
		firm_strategies = @doc.xpath("//firm_strategies")
		firm_revenues = @doc.xpath("//firm_revenues")
		puts(i.to_s + "," + firm_strategies.to_s.gsub('<firm_strategies>{','').gsub('}</firm_strategies>','') + 
			firm_revenues.to_s.gsub('<firm_revenues>{','').gsub('}</firm_revenues>',''))
	end
end


