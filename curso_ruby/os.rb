require 'os'

puts "Sistema operacional: #{OS.host_os}"
puts "É Windows? #{OS.windows?}"
puts "É Mac? #{OS.mac?}"
puts "É Linux? #{OS.linux?}"
puts "Número de CPUs: #{OS.cpu_count}"
puts "Bits do sistema: #{OS.bits} bits"
