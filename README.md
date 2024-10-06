# Cartisian_robotics_system
Components to order:
  -> We used A4988 : https://www.amazon.co.uk/Stepstick-Stepper-Printer-Suitable-Arduino/dp/B07XRF8YPX/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.28dvMVAE4lZBrPje-e5Y_OZqQs2euyzUrYHp96fqEpWaPLjVY_tKEgYfL-hwD62dSk914vvLqmjyLiM9DHowMdSn01j07Dx10veZ1KFwrOhRGVVImavU_Bf3vNK6gjOJ-7-lLJnmEZnO2F89dQYksOwIgBFvy5B8OX6hisxL6WK9YoWe7uAZPKaffrqnfyXQpSeFFI2A5LupyBGCO7w9tpvsFIRR29eMBg1mFVMSawwL8ieVec65RXC1KsiuVjrjV__tB6qav4BUITdyHdTW6B2O2_ZG0XlC9wTS5ItDgJY.tDKCWxF8bkXCWqfNbLb7byqkYbqQBFgLVYQNUKMJSFQ&dib_tag=se&keywords=a4988&qid=1728215736&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1
  -> You can try drv8825: https://www.amazon.co.uk/DRV8825-Stepper-Suitable-8-2V-45V-Printer/dp/B0CCRXGKLV/ref=sr_1_3?crid=2IQTC0DKUHTM8&dib=eyJ2IjoiMSJ9.omxmiFuPkf8zCsbViB5fkSTaZqIMiOf1AS6xpwY1dHNfuA8NiWGxzQ_KF39ELQ_VwhdiyiVlck-qrIa0qhE3t9E2MzZ6k_Qx4Mcq3ZQDMKOpZEQMxbDwHudoRwwFXf-syVxvICPZBz9baMkrwTb3EKtR4DE9lOBZ3hauZ4luJq3awm1t60mswaxqVU_DAolYCNISojTQ_yFX0q5Oc--ZSNxp6C8qc-8jEnQqQEiSsauu5EQ_SM0oBdqlcUeQPeOD4Lm-p0tFURwmqK8Ds8AehHUDKofSlArMCv38fktyeyk.reb8vbp3qZ9T66gLI8CzaM5Ly6qZP4vkaXPWnmboy3c&dib_tag=se&keywords=drv8825&qid=1728215793&sprefix=drv8825%2Caps%2C151&sr=8-3
  -> or POLOLU A4988 : https://www.amazon.co.uk/Printer-Stepper-Microsteps-Heatsink-Screwdriver/dp/B0CGBQG89W/ref=sr_1_2?crid=3L9YZFFY2BAVU&dib=eyJ2IjoiMSJ9.dkP8nZb52hEveY1ncvlg9gbiax3S_wLgkGk339WFYe9mVq9PsFfn1i7bhoQVk-7yDZW1TFVJHcZSQ_51kiWT22EMVpgKh7SVGbKdJbNvXmtHLOF8lwlbrvQR6VPclOj1yTjZqbW0jeftEUvLPI73oVbR6UtHzpr__dsS2f68Ubq-mL8b99OaJ8neNgdNiMVhua97pbx9RAlmfcDYSAcKQ3DsGoObmUlUEQiX4kkQ4eYp__J5bAeDNvPVuiKAKCdwDPcK_YCr7BYsEY8-49qi_bubijrvvjq_Vf3U-XZxju4.jsr0f5MpLny55HoepSQjJu5tfDu6xpXZjMIgA8J2nhI&dib_tag=se&keywords=pololu+a4988&qid=1728215841&sprefix=polulu+a4988%2Caps%2C185&sr=8-2
  -> In my opinion the best way to privent issues with a4988 is ti use special shields: https://www.amazon.co.uk/Printer-DRV8825-Stepper-Control-Expansion/dp/B07NSVN9BR/ref=sr_1_2?crid=11FLSRGNUF9P&dib=eyJ2IjoiMSJ9._Tkh7Y5h8zmVvX2KwstUDFZNBJAEI2zzks_FoIyUtEd7qxuGPi8r94uI1D-REuYuYb268TS12nU9--rmkuZohoqrz2WDdxVBr73p4r0Zu0mvQHjbd7yjRfH7rGWc5ZHt3logGJ3hsHTQWattCZ1IYzfcRBXsP4XbtTTQYgTHnv929xLlaErKlkN3j5Yny-vdYbFBEsray5YA5qSOuqBcQYcufQOWMpBSEIlXSszu_1AGmkIsKyMK5l_vqGaxefKQXx4yS9JVNHT8NkLJ0PBnotjHpBreU2z_HW5P7BpfyzQ.0kdZVrA8jX9xrh2gHeL6j33jFFEFsjjnDp_UJbounro&dib_tag=se&keywords=a4988+shield&qid=1728215920&sprefix=a4988+shiel%2Caps%2C192&sr=8-2

  What to do to minimize chance of hip burning:
    -> Use 100 microF capcitor as shown on a diagram to prevent voltage spikes
    -> Current has to be 0.35 A per motor
    -> Voltage has to be approximately 12V
    -> Isure that the motor wires do not disconnect while the system is powered.
    -> Try to keep controllers appart 

  Why to use shield:
    -> It is better to use shield becouse it solves all the above problems

