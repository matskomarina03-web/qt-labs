from tok import token
import telebot
from telebot import types
import sqlite3
import json
bot = telebot.TeleBot(token)
ADMIN_ID = 5268765168
@bot.message_handler(commands=['id'])
def get_id(message):
    bot.send_message(message.chat.id, f"Ваш chat id: {message.chat.id}")
@bot.message_handler(commands=['start'])
def start(message):
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

    btn1 = types.KeyboardButton("Після 9 класу")
    btn2 = types.KeyboardButton("Після 11 класу")
    btn3 = types.KeyboardButton("Магістр")
    btn4 = types.KeyboardButton("Документи для вступу")
    btn5 = types.KeyboardButton("Контакти")
    btn6 = types.KeyboardButton("Подати заявку")

    markup.add(btn1, btn2)
    markup.add(btn3, btn4)
    markup.add(btn5, btn6)

    bot.send_message(
        message.chat.id,
        "Вітаємо у Telegram-боті Комунального закладу вищої освіти «Кременчуцька гуманітарно-технологічна академія» Полтавської обласної ради\n\nПісля якого класу ви хочете вступати?",
        reply_markup=markup
    )


@bot.message_handler(content_types=['text'])
def menu(message):

    if message.text == "Після 9 класу":
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Дошкільна освіта (ФПО)")
        btn2 = types.KeyboardButton("Початкова освіта (ФПО)")
        btn3 = types.KeyboardButton("Українська мова і література (ФПО)")
        btn4 = types.KeyboardButton("Фізична культура і спорт (ФПО)")
        btn5 = types.KeyboardButton("Комп'ютерні науки (ФПО)")
        btn6 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3, btn4)
        markup.add(btn5)
        markup.add(btn6)

        bot.send_message(message.chat.id, "Оберіть спеціальність:", reply_markup=markup)

    

    elif message.text == "Дошкільна освіта (ФПО)":
        bot.send_message(message.chat.id,
                         "Фахова передвища освіта\n"
                         "Спеціальність: А2 Дошкільна освіта\n"
                         "Термін навчання: 3 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 17 500 грн/рік\n"
                         "Вступні випробування:\n"
                         "• співбесіда з української мови\n"
                         "• мотиваційний лист\n"
                        "Мотиваційний лист подається через електронний кабінет вступника під час подачі документів")
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ДО):")
        btn2 = types.KeyboardButton("Переваги (ДО):")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги (ДО):":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• сертифікатні програми\n"
        "• одночасне навчання і робота\n"
        "• навчання за ваучером"
    )
    
    elif message.text == "Можливості працевлаштування (ДО):":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вихователь дітей раннього та дошкільного віку\n"
        "• вихователь у центрах розвитку дітей, санаторіях\n"
        "• асистент логопеда та дефектолога\n"
        "• керівник гуртка образотворчого мистецтва\n"
        "• вихователь-гувернер, аніматор\n"
        "• інструктор з фізичного виховання у закладі дошкільної освіти"
    )
        
    elif message.text == "Початкова освіта (ФПО)":
        bot.send_message(message.chat.id,
                         "Фахова передвища освіта\n"
                         "Спеціальність: А3 Початкова освіта\n"
                         "Термін навчання: 3 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 17 500 грн/рік\n"
                         "Вступні випробування:\n"
                         "• співбесіда з української мови\n"
                         "• мотиваційний лист\n"
                        "Мотиваційний лист подається через електронний кабінет вступника під час подачі документів")
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ПО):")
        btn2 = types.KeyboardButton("Переваги (ПО):")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги (ПО):":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
    
    elif message.text == "Можливості працевлаштування (ПО):":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вчитель початкових класів;\n"
        "• асистент вчителя;\n"
        "• вихователь групи продовженого дня;\n"
        "• педагог-організатор;\n"
        "• керівник гуртка;\n"
        "• працівник закладу позашкільної освіти.\n"
    )
    

    elif message.text == "Українська мова і література (ФПО)":
        bot.send_message(
        message.chat.id,
        "Фахова передвища освіта\n"
        "Спеціальність: В11 Філологія\n"
        "Освітньо-професійна програма:\n"
        "\"Українська і англійська мови: переклад та редагування\"\n\n"
        "Освітня кваліфікація:\n"
        "• фахівець із перекладу\n"
        "• фахівець із редагування\n\n"
        "Термін навчання: 3 роки 10 місяців\n"
        "Вартість навчання:\n"
        "денна форма — 18 000 грн/рік\n\n"
        "Вступні випробування:\n"
        "• співбесіда з української мови\n"
        "• мотиваційний лист\n"
        "Мотиваційний лист подається через електронний кабінет вступника під час подачі документів"
    )

        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (УМЛ)")
        btn2 = types.KeyboardButton("Переваги (УМЛ)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги (УМЛ)":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
    
    elif message.text == "Можливості працевлаштування (УМЛ)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вчитель мови та літератури\n"
        "• перекладач\n"
        "• редактор, копірайтер, коректор\n"
        "• контент-менеджер"
    )
        
    elif message.text == "Фізична культура і спорт (ФПО)":
        bot.send_message(
        message.chat.id,
        "Фахова передвища освіта\n"
        "Спеціальності:\n"
        "• А7 Фізична культура і спорт\n"
        "• А4.11 Середня освіта (Фізична культура)\n\n"
        "Термін навчання:\n"
        "• 3 роки 10 місяців\n"
        "• 2 роки 10 місяців\n\n"
        "Вартість навчання:\n"
        "денна форма — 19 000 грн/рік\n\n"
        "Вступні випробування:\n"
        "• співбесіда\n"
        "• мотиваційний лист\n"
        "Мотиваційний лист подається через електронний кабінет вступника під час подачі документів"
    )

        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ФК)")
        btn2 = types.KeyboardButton("Переваги (ФК)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
        
    
    elif message.text == "Переваги (ФК)":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
    
    elif message.text == "Можливості працевлаштування (ФК)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• тренер з обраного виду спорту\n"
        "• фахівець зі спортивної реабілітації\n"
        "• учитель фізичної культури\n"
        "• учитель предмета «Захист України»\n"
        "• інструктор з фізичної підготовки"
    )
        
    
    elif message.text == "Комп'ютерні науки (ФПО)":
        bot.send_message(
        message.chat.id,
        "Фахова передвища освіта\n"
        "Спеціальність: F3 Комп'ютерні науки\n"
        "Термін навчання: 3 роки 10 місяців\n"
        "Вартість навчання:\n"
        "денна форма — 18 000 грн/рік\n"
        "Вступні випробування:\n"
        "• співбесіда з математики\n"
        "• мотиваційний лист\n"
        "Мотиваційний лист подається через електронний кабінет вступника під час подачі документів"
    )
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (КН)")
        btn2 = types.KeyboardButton("Переваги (КН)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги (КН)":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
    
    elif message.text == "Можливості працевлаштування (КН)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• програміст\n"
        "• веб-розробник\n"
        "• тестувальник програмного забезпечення (QA)\n"
        "• системний адміністратор\n"
        "• фахівець з кібербезпеки\n"
        "• розробник мобільних додатків"
    )

    elif message.text == "Після 11 класу":
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Фаховий молодший бакалавр")
        btn2 = types.KeyboardButton("Бакалавр")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть рівень освіти:", reply_markup=markup)

    

    elif message.text == "Фаховий молодший бакалавр":
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Дошкільна освіта (ФМБ)")
        btn2 = types.KeyboardButton("Початкова освіта (ФМБ)")
        btn3 = types.KeyboardButton("Фізична культура і спорт (ФМБ)")
        btn4 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        markup.add(btn4)
        bot.send_message(message.chat.id, "Оберіть спеціальність:", reply_markup=markup)
    
    elif message.text == "Дошкільна освіта (ФМБ)":
        bot.send_message(message.chat.id,
                         "Фаховий молодший бакалавр\n"
                         "Спеціальність: A2 Дошкільна освіта\n"
                         "Термін навчання: 1 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 19 000 грн/рік\n"
                         "заочна форма — 15 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування ДО:")
        btn2 = types.KeyboardButton("Переваги ДO:")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Початкова освіта (ФМБ)":
        bot.send_message(message.chat.id,
                         "Фаховий молодший бакалавр\n"
                         "Спеціальність: A3 Початкова освіта\n"
                         "Термін навчання: 1 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 19 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування ПО:")
        btn2 = types.KeyboardButton("Переваги ПО:")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Фізична культура і спорт (ФМБ)":
        bot.send_message(message.chat.id,
                         "Фаховий молодший бакалавр\n"
                         "Спеціальність: А4.11 Середня освіта (Фізична культура)\n"
                         "Термін навчання: 1 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 19 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ФК)")
        btn2 = types.KeyboardButton("Переваги (ФК)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
        






















        
    elif message.text == "Бакалавр":
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Дошкільна освіта (Бакалавр)")
        btn2 = types.KeyboardButton("Початкова освіта (Бакалавр)")
        btn3 = types.KeyboardButton("Філологія (Бакалавр)")
        btn4 = types.KeyboardButton("Фізична культура і спорт (Бакалавр)")
        btn5 = types.KeyboardButton("Психологія (Бакалавр)")
        btn6 = types.KeyboardButton("Менеджмент (Бакалавр)")
        btn7 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3, btn4)
        markup.add(btn5, btn6)
        markup.add(btn7)
        bot.send_message(message.chat.id, "Оберіть спеціальність:", reply_markup=markup)
    
    elif message.text == "Дошкільна освіта (Бакалавр)":
        bot.send_message(message.chat.id,
                         "Бакалавр\n"
                         "Спеціальність: A2 Дошкільна освіта\n"
                         "Термін навчання: 1 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 22 000 грн/рік\n"
                         "заочна форма — 16 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування ДО:")
        btn2 = types.KeyboardButton("Переваги ДO:")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги ДO:":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• сертифікатні програми\n"
        "• одночасне навчання і робота\n"
        "• навчання за ваучером"
    )
    
    elif message.text == "Можливості працевлаштування ДО:":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вихователь дітей раннього та дошкільного віку\n"
        "• вихователь у центрах розвитку дітей, санаторіях\n"
        "• асистент логопеда та дефектолога\n"
        "• керівник гуртка образотворчого мистецтва\n"
        "• вихователь-гувернер, аніматор\n"
        "• інструктор з фізичного виховання у закладі дошкільної освіти"
    )
    
    elif message.text == "Початкова освіта (Бакалавр)":
        bot.send_message(message.chat.id,
                         "Бакалавр\n"
                         "Спеціальність: A3 Початкова освіта\n"
                         "Термін навчання: 1 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 22 000 грн/рік\n"
                         "заочна форма — 16 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування ПО:")
        btn2 = types.KeyboardButton("Переваги ПО:")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)
        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
    
    elif message.text == "Переваги ПО:":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• сертифікатні програми\n"
        "• одночасне навчання і робота\n"
        "• навчання за ваучером"
    )
    
    elif message.text == "Можливості працевлаштування ПО:":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вихователь дітей раннього та дошкільного віку\n"
        "• вихователь у центрах розвитку дітей, санаторіях\n"
        "• асистент логопеда та дефектолога\n"
        "• керівник гуртка образотворчого мистецтва\n"
        "• вихователь-гувернер, аніматор\n"
        "• інструктор з фізичного виховання у закладі дошкільної освіти"
    )
    
    elif message.text == "Філологія (Бакалавр)":
        bot.send_message(message.chat.id,
                         "Бакалавр\n"
                         "Спеціальність: В11 Філологія\n"
                         "Термін навчання: 3 роки 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 22 000 грн/рік")
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ФБ)")
        btn2 = types.KeyboardButton("Переваги (ФБ)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)

    elif message.text == "Переваги (ФБ)":
        bot.send_message(
        message.chat.id,
        "Переваги навчання:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
        
    elif message.text == "Можливості працевлаштування (ФБ)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• вчитель мови та літератури\n"
        "• перекладач\n"
        "• редактор, копірайтер, коректор\n"
        "• контент-менеджер"
    )
        
    
    elif message.text == "Фізична культура і спорт (Бакалавр)":
        bot.send_message(message.chat.id,
                         "Бакалавр\n"
                         "Спеціальність: А7 Фізична культура і спорт\n"
                         "Термін навчання: 3 рік 10 місяці\n"
                         "Вартість навчання:\n"
                         "денна форма — 22 000 грн/рік")
        
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Можливості працевлаштування (ФК Б)")
        btn2 = types.KeyboardButton("Переваги (ФK Б)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)
        
    
    elif message.text == "Переваги (ФK Б)":
        bot.send_message(
        message.chat.id,
        "Наші переваги:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• можливість проживати в зручному, комфортабельному гуртожитку\n"
        "• активне студентське життя\n"
        "• сприяння працевлаштуванню за спеціальністю з можливістю навчатися за індивідуальним графіком"
    )
    
    elif message.text == "Можливості працевлаштування (ФК Б)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• тренер з обраного виду спорту\n"
        "• фахівець зі спортивної реабілітації\n"
        "• учитель фізичної культури\n"
        "• учитель предмета «Захист України»\n"
        "• інструктор з фізичної підготовки"
    )
    
    elif message.text == "Психологія (Бакалавр)":
        bot.send_message(message.chat.id,
                        "Бакалавр\n"
                        "Спеціальність: C4 Психологія\n"
                        "Форма навчання: денна\n"
                        "Вартість навчання:\n"
                        "38 964 грн/рік"
    )
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Переваги (П)")
        btn2 = types.KeyboardButton("Працевлаштування (П)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)


    elif message.text == "Переваги (П)":
        bot.send_message(
        message.chat.id,
        "Переваги навчання:\n"
        "• підготовка конкурентоспроможних фахівців\n"
        "• поєднання теорії та практики\n"
        "• розвиток навичок консультування та психореабілітації\n"
        "• підготовка до роботи з різними категоріями населення\n"
        "• студентоцентроване навчання\n"
        "• можливість академічної мобільності та обмінів"
    )


    elif message.text == "Працевлаштування (П)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• психолог, практичний психолог\n"
        "• спеціаліст з підбору персоналу\n"
        "• робота в правоохоронних органах та військових структурах\n"
        "• працівник служб довіри та допомоги\n"
        "• робота у закладах освіти та реабілітаційних центрах"
    )
        
    elif message.text == "Менеджмент (Бакалавр)":
        bot.send_message(message.chat.id,
                         "Бакалавр\n"
                        "Спеціальність: D3 Менеджмент\n"
                        "Форма навчання: денна\n"
                        "Вартість навчання:\n"
                        "38 964 грн/рік"
    )
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Переваги (Менеджмент)")
        btn2 = types.KeyboardButton("Працевлаштування (Менеджмент)")
        btn3 = types.KeyboardButton("⬅ Назад")

        markup.add(btn1, btn2)
        markup.add(btn3)

        bot.send_message(message.chat.id, "Оберіть, що вас цікавить:", reply_markup=markup)


    elif message.text == "Переваги (Менеджмент)":
        bot.send_message(
        message.chat.id,
        "Переваги навчання:\n"
        "• наявні місця регіонального замовлення\n"
        "• навчання у форматі офлайн\n"
        "• комфортний гуртожиток\n"
        "• активне студентське життя\n"
        "• допомога у працевлаштуванні\n"
        "• можливість навчатися за індивідуальним графіком"
    )


    elif message.text == "Працевлаштування (Менеджмент)":
        bot.send_message(
        message.chat.id,
        "Можливості працевлаштування:\n"
        "• керівник підрозділу або філії\n"
        "• HR-менеджер / менеджер з персоналу\n"
        "• бізнес-консультант\n"
        "• менеджер з логістики\n"
        "• менеджер з маркетингу\n"
        "• фінансовий спеціаліст"
    )


    elif message.text == "Магістр":
            bot.send_message(message.chat.id,
                "Магістратура\n\n"
                "Освітньо-професійна програма: Управління закладом освіти\n"
                "Спеціальність: A1 Освітні науки\n"
                "Кваліфікація: Магістр освітніх, педагогічних наук\n"
                "Професійна кваліфікація: керівник закладу освіти, викладач ЗВО\n"
                "Термін навчання: 1 рік 4 місяці\n"
                "Форма навчання: денна, заочна (дистанційно)\n\n"
                "Вступні випробування:\n"
                "ЄВІ (2024–2026)\n"
                "ЄФВВ з педагогіки та психології (2025–2026)\n"
                "або вступні оцінювання в ЗВО за спеціальними умовами\n"
                "Основне про ЄВІ/ЄФВВ: https://testportal.gov.ua/osnovne-pro-yevi-yefvv-2026/\n"
                "Порядок вступу в магістратуру: https://testportal.gov.ua/vstupni-do-magistratury-6/"

        )

    elif message.text == "Контакти":
        bot.send_message(
            message.chat.id,
            "Адреса: м. Кременчук, вул. Валентини Федько, 33\n\n"
            "Телефон приймальної комісії: +380687772265\n+38 05367 58470\n+380685387820\n\n"
            "Email: krem_ped_k@ukr.net"
        )

    elif message.text == "Документи для вступу":
        bot.send_message(message.chat.id,
                "Перелік документів для вступу:\n\n"
                "1. Копія документа, що посвідчує особу\n"
                "(для ID-картки — 2 копії витягу з реєстру)\n"
                "2. Копія документа про освіту та додатка\n"
                "3. Копія ідентифікаційного коду\n"
                "4. Військовий квиток / приписне\n"
                "(для військовозобов'язаних)\n"
                "5. Документи на пільги (за наявності)\n"
                "6. 2 фотокартки 3×4 см\n"
                "7. Медична довідка 086-о\n"
                "8. Карта щеплень (форма 063)\n"
                "9. Паперовий швидкозшивач з файлами"
    )


    elif message.text == "⬅ Назад":
        markup = types.ReplyKeyboardMarkup(resize_keyboard=True)

        btn1 = types.KeyboardButton("Після 9 класу")
        btn2 = types.KeyboardButton("Після 11 класу")
        btn3 = types.KeyboardButton("Магістр")
        btn4 = types.KeyboardButton("Документи для вступу")
        btn5 = types.KeyboardButton("Контакти")
        btn6 = types.KeyboardButton("Подати заявку")

        markup.add(btn1, btn2)
        markup.add(btn3, btn4)
        markup.add(btn5, btn6)

        bot.send_message(
            message.chat.id,
            "Повернення до головного меню",
            reply_markup=markup
        )
    elif message.text == "Подати заявку":
        msg = bot.send_message(message.chat.id, "Введіть ваше ПІБ:")
        bot.register_next_step_handler(msg, get_name)
user_data = {}



def get_name(message):
    user_data[message.chat.id] = {"name": message.text}

    msg = bot.send_message(message.chat.id, "Введіть номер телефону:")
    bot.register_next_step_handler(msg, get_phone)


def get_class(message):
    user_data[message.chat.id]["class"] = message.text

    msg = bot.send_message(message.chat.id, "Яка спеціальність вас цікавить?")
    bot.register_next_step_handler(msg, get_speciality)


conn = sqlite3.connect("applicants.db", check_same_thread=False)
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS applicants (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    phone TEXT,
    class TEXT,
    speciality TEXT
)
""")

conn.commit()

def save_to_json(data):
    try:
        with open("applications.json", "r", encoding="utf-8") as file:
            applications = json.load(file)
    except FileNotFoundError:
        applications = []

    applications.append(data)

    with open("applications.json", "w", encoding="utf-8") as file:
        json.dump(applications, file, ensure_ascii=False, indent=4)
@bot.message_handler(commands=['applications'])
def show_applications(message):
    if message.chat.id != ADMIN_ID:
        bot.send_message(message.chat.id, "У вас немає доступу.")
        return

    try:
        with open("applications.json", "r", encoding="utf-8") as file:
            rows = json.load(file)
    except FileNotFoundError:
        rows = []

    if not rows:
        bot.send_message(message.chat.id, "Заявок поки немає.")
        return

    text = " Список заявок:\n\n"

    for row in rows:
        text += (
            f" {row['name']}\n"
            f" {row['phone']}\n"
            f" {row['class']}\n"
            f" {row['speciality']}\n\n"
        )

    bot.send_message(message.chat.id, text)
def get_speciality(message):
    user_data[message.chat.id]["speciality"] = message.text

    data = user_data[message.chat.id]

    save_to_json(data)

    bot.send_message(
        ADMIN_ID,
        f"Нова заявка!\n\n"
        f"ПІБ: {data['name']}\n"
        f"Телефон: {data['phone']}\n"
        f"Після класу: {data['class']}\n"
        f"Спеціальність: {data['speciality']}"
    )

    bot.send_message(
        message.chat.id,
        "Дякуємо 💛 Ваша заявка прийнята. З вами зв’яжеться приймальна комісія."
    )

    del user_data[message.chat.id]



def get_phone(message):
    phone = message.text.strip()

    if not phone.startswith("+380") or len(phone) != 13 or not phone[1:].isdigit():
        msg = bot.send_message(
            message.chat.id,
            "Введіть номер у форматі +380XXXXXXXXX"
        )
        bot.register_next_step_handler(msg, get_phone)
        return

    user_data[message.chat.id]["phone"] = phone

    msg = bot.send_message(message.chat.id, "Після якого класу вступаєте?")
    bot.register_next_step_handler(msg, get_class)
bot.polling()