// Analog Pin 0
int AnalogRead_PC0(void){
	
	int ADCValue = 0;

   	// Set ADC clock prescaler to 128. If this is too low, won't get good resolution
  	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 

	// Set the ADC Reference to AVCC
   	ADMUX &= ~(1 << REFS1);  
   	ADMUX |= (1 << REFS0);  

	// Disable left adjust (use both ADCH and ADCL)
   	ADMUX &= ~(1 << ADLAR);

   	// Set MUX[3:0] to 0000 to enable ADC0
	ADMUX &= ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0); 

	// Disables PRR bit, so ADC can be enabled
	//PRR &= ~(1<<PRADC); 

	// Enable ADC   
	ADCSRA |= (1 << ADEN);  

	// Start A2D Conversions
	ADCSRA |= (1 << ADSC); 

	// Wait for ADC to complete	
	while (ADCSRA & (1<<ADSC));

	// Store both bytes into unsigned int
	ADCValue = (ADCL | (ADCH << 8)); 
	
	#ifdef DEBUG
		USART_TransmitString("Analog Pin 0 (High,Low): ", 28);
		unsigned char HIGH = (ADCValue>>8); 
		unsigned char LOW = (unsigned char)ADCValue; 		
		USART_Transmit(HIGH);
		USART_Transmit(44); 
		USART_Transmit(LOW); 
		USART_Transmit(CARRIAGERETURN); 
	#endif
	// Return combination as int
	return  (ADCValue); 
}




// Analog Pin 1
int AnalogRead_PC1(void){
	
	int ADCValue = 0;

	// Set ADC clock prescaler to 128. If this is too low, won't get good resolution
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 

	// Set the ADC Reference to AVCC
   	ADMUX &= ~(1 << REFS1);  
   	ADMUX |= (1 << REFS0);  

	// Disable left adjust (use both ADCH and ADCL)
   	ADMUX &= ~(1 << ADLAR);

   	// Set MUX[3:0] to 0001 to enable ADC1
	ADMUX &= ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1); 
	ADMUX |=  (1<<MUX0); 

	// Disables PRR bit, so ADC can be enabled
	//PRR &= ~(1<<PRADC); 

	// Enable ADC   
	ADCSRA |= (1 << ADEN);  

	// Start A2D Conversions
	ADCSRA |= (1 << ADSC); 

	// Wait for ADC to complete	
	while (ADCSRA & (1<<ADSC));

	// Store both bytes into unsigned int
	ADCValue = (ADCL | (ADCH << 8)); 

	#ifdef DEBUG
		USART_TransmitString("Analog Pin 1 (High,Low): ", 28);
		unsigned char HIGH = (ADCValue>>8); 
		unsigned char LOW = (unsigned char)ADCValue; 		
		USART_Transmit(HIGH);
		USART_Transmit(44); 
		USART_Transmit(LOW); 
		USART_Transmit(CARRIAGERETURN); 
	#endif

	// Return combination as int
	return  (ADCValue); 
}




// Analog Pin 2
int AnalogRead_PC2(void){
	
	int ADCValue = 0;

	// Set ADC clock prescaler to 128. If this is too low, won't get good resolution
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 

	// Set the ADC Reference to AVCC
   	ADMUX &= ~(1 << REFS1);  
   	ADMUX |= (1 << REFS0);  

	// Disable left adjust (use both ADCH and ADCL)
   	ADMUX &= ~(1 << ADLAR);

   	// Set MUX[3:0] to 0010 to enable ADC2
	ADMUX &= ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX0); 
	ADMUX |=  (1<<MUX1); 

	// Disables PRR bit, so ADC can be enabled
	//PRR &= ~(1<<PRADC); 

	// Enable ADC   
	ADCSRA |= (1 << ADEN);  

	// Start A2D Conversions
	ADCSRA |= (1 << ADSC); 

	// Wait for ADC to complete	
	while (ADCSRA & (1<<ADSC));

	// Store both bytes into unsigned int
	ADCValue = (ADCL | (ADCH << 8)); 

	#ifdef DEBUG
		USART_TransmitString("Analog Pin 2 (High,Low): ", 28);
		unsigned char HIGH = (ADCValue>>8); 
		unsigned char LOW = (unsigned char)ADCValue; 		
		USART_Transmit(HIGH);
		USART_Transmit(44); 
		USART_Transmit(LOW); 
		USART_Transmit(CARRIAGERETURN); 
	#endif

	// Return combination as int
	return  (ADCValue); 
}
